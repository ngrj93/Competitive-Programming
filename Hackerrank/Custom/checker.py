# Python program to check if strings are rotations of
# each other or not

# Function checks if passed strings (str1 and str2)
# are rotations of each other
def areRotations(string1, string2):
	size1 = len(string1)
	size2 = len(string2)
	temp = ''

	# Check if sizes of two strings are same
	if size1 != size2:
		return 0

	# Create a temp string with value str1.str1
	temp = string1 + string1

	# Now check if str2 is a substring of temp
	# string.count returns the number of occurences of
	# the second string in temp
	if (temp.count(string2)> 0):
		return 1
	else:
		return 0

# Driver program to test the above function
t = input();

while t != 0:
	t = t - 1;
	string1 = raw_input();
	string2 = raw_input();

	if areRotations(string1, string2):
			print "YES"
	else:
			print "NO"

# This code is contributed by Bhavya Jain

