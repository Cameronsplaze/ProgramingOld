from flask import render_template, flash, redirect, url_for, request
from app import app, db
from app.forms import LoginForm, RegistrationForm, BiddingForm, PrimeForm
from app.models import User, Bid, Vegi
from flask_login import current_user, login_user, logout_user, login_required
from werkzeug.urls import url_parse

@app.route('/', methods=['GET', 'POST'])


@app.route('/index', methods=['GET', 'POST'])
@login_required
def index():
	form = BiddingForm()
	yourBids = Bid.query.filter_by(user_id=current_user.username).all()
	allVegetables = Vegi.query.all()
	if request.method=='POST':
		if form.validate_on_submit():
			if Vegi.query.filter_by(vegetable=form.vegetable.data).first() is None:
				flash('VERBOTEN!! (vegi not found)')
				return redirect(url_for('index'))
			if current_user.get_money() < form.amount.data:
				flash('VERBOTEN!! (not enough izhk)')
				return redirect(url_for('index'))
			prevBid = Bid.query.filter_by(vegetable=form.vegetable.data).first()
			if prevBid is not None:
				current_user.set_money(current_user.get_money()+prevBid.get_amount())
				current_user.set_money(current_user.get_money()-form.amount.data)
				prevBid.set_amount(form.amount.data)
				db.session.commit()
			else:
				myBid = Bid(amount=form.amount.data, vegetable=form.vegetable.data,user_id=current_user.username)
				current_user.set_money(current_user.get_money()-form.amount.data)
				db.session.add(myBid)
				db.session.commit()
			flash('Crangrats! Your bid is placed!')

	return render_template('index.html', title='Home', form=form, yourBids=yourBids, allVegetables=allVegetables)

@app.route('/login', methods=['GET', 'POST'])
def login():
	if current_user.is_authenticated:
		return redirect(url_for('index'))
	form = LoginForm()
	if form.validate_on_submit():
		user = User.query.filter_by(username=form.username.data).first()
		if user is None or not user.check_password(form.password.data):
			flash('VERBOTEN!! Invalid username or password')
			return redirect(url_for('login'))
		login_user(user, remember=form.remember_me.data)
		next_page = request.args.get('next')
		if not next_page or url_parse(next_page).netloc != '':
			next_page = url_for('index')
		return redirect(next_page)
	return render_template('login.html', title='Sign In', form=form)

@app.route('/logout')
def logout():
	logout_user()
	return redirect(url_for('index'))

@app.route('/register', methods=['GET', 'POST'])
def register():
	if current_user.is_authenticated:
		return redirect(url_for('index'))
	form = RegistrationForm()
	if form.validate_on_submit():
		user = User(username=form.username.data, money='100')
		user.set_password(form.password.data)
		db.session.add(user)
		db.session.commit()
		flash('Congrats! You can now buy stuff!!')
		return redirect(url_for('login'))
	return render_template('register.html', title='Register', form=form)

@app.route('/prime', methods=['GET', 'POST'])
@login_required
def prime():
	if current_user.username != -1:
		return redirect(url_for('index'))
	form = PrimeForm()
	allBids = Bid.query.all()
	if form.validate_on_submit():
		if Vegi.query.filter_by(vegetable=form.vegetable.data).first() is None:
			newVegi = Vegi(vegetable=form.vegetable.data)
			db.session.add(newVegi)
			db.session.commit()
			flash('Congtats! Vegi Added')
		else:
			flash('VERBOTEN!! Vegi already there')
	return render_template('prime.html', title='Prime Account', form=form, theBids=allBids)


