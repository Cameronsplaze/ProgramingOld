from flask_wtf import FlaskForm
from wtforms import StringField, PasswordField, BooleanField, IntegerField, SubmitField, validators
from wtforms.validators import ValidationError, DataRequired, EqualTo, NumberRange
from app.models import User, Bid, Vegi
from flask_login import current_user

class LoginForm(FlaskForm):
	username = IntegerField('Username', validators=[DataRequired(), NumberRange(min=-1, max=999999)])
	# username = IntegerField('ID Number', validators=[DataRequired()])
	password = PasswordField('Password (Optional)')
	remember_me = BooleanField('Remember Me')
	submit = SubmitField('Sign In')


class RegistrationForm(FlaskForm):
	username = IntegerField('ID Number', validators=[DataRequired(), NumberRange(min=-1, max=999999)])
	password = PasswordField('Password (Optional)', validators=[])
	password2 = PasswordField('Repeat Password', validators=[EqualTo('password')])
	submit = SubmitField('Register')

	def validate_username(self, username):
		user = User.query.filter_by(username=username.data).first()
		if user is not None:
			raise ValidationError('Username ID already in use. Choose another')

class BiddingForm(FlaskForm):
	vegetable = StringField('Vegetable', validators=[DataRequired()])
	amount = IntegerField('Amount for Bid', validators=[DataRequired(), NumberRange(min=0, max=100)])
	submit = SubmitField('Place Bid')

class PrimeForm(FlaskForm):
	vegetable = StringField('Vegetable', validators=[])
	submit = SubmitField('Add Vegi')

	def validate_add(self, vegetable):
		if vegi_exists(vegetable):
			raise ValidationError('VERBOTEN!! (vegi already there!)')