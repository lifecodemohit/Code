from sys import argv

script, user_name = argv

prompt=">"

print "Hi %s, I'm the %s script."%(user_name, script)
print "What is your age %s?"%(user_name)
age=raw_input(prompt)
print "Where do you live %s?"%(user_name)
live=raw_input(prompt)
print "Did you like the programme %s?"%(user_name)
like=raw_input("like or dont like?" + prompt)

print "So %s years old living in %s. And you %s my programme!"%(age, live, like)