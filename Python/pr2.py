import time

def time_decorator(func):
	def funcWihtTime(*args, **kwargs):
		return func(*args, **kwargs)
	print(time.time())
	

		