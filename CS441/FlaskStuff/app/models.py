from datetime import datetime
from app import db, login
from flask_login import UserMixin
from werkzeug.security import generate_password_hash, check_password_hash


class User(UserMixin, db.Model):
	id = db.Column(db.Integer, primary_key=True)
	username = db.Column(db.Integer, index=True, unique=True)
	money = db.Column(db.Integer, unique =False)
	password_hash = db.Column(db.String(128))
	# bids = db.relationship('Bid', backref='bidder', lazy='dynamic')

	def __repr__(self):
		return '<User: {}'.format(self.username) + ' Money: {}>'.format(self.money)

	def set_password(self, password):
		self.password_hash = generate_password_hash(password)

	def check_password(self, password):
		return check_password_hash(self.password_hash, password)

	def set_money(self, amount):
		User.query.get(self.id).money = amount
		db.session.commit()

	def get_money(self):
		return User.query.get(self.id).money

@login.user_loader
def load_user(id):
	return User.query.get(int(id))


class Bid(db.Model):
	id = db.Column(db.Integer, primary_key=True)
	amount = db.Column(db.Integer)
	vegetable = db.Column(db.String)
	user_id = db.Column(db.Integer)
	# user_id = db.Column(db.Integer, db.ForeignKey('user.id'))

	def __repr__(self):
		return '<User: {},'.format(self.user_id) + ' vegetable: {},'.format(self.vegetable) + ' amount: {}>'.format(self.amount)

	def get_amount(self):
		return Bid.query.get(self.id).amount

	def get_vegetable(self):
		return Bid.query.get(self.id).amount

	def set_amount(self, newAmount):
		Bid.query.get(self.id).amount = newAmount
		db.session.commit()

	def set_vegetable(self, newVegi):
		Bid.query.get(self.id).vegetable = newVegi
		db.session.commit()


class Vegi(db.Model):
	id = db.Column(db.Integer, primary_key=True)
	vegetable = db.Column(db.String)

	def __repr__(self):
		return '{}'.format(self.vegetable)
		
	def vegi_add(self, vegi):
		addVegi = Vegi(vegetable=vegi)
		db.session.add(addVegi)
		db.session.commit()