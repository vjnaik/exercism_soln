# Determine if a year is a leap year
# IsLeapYear ? Year
# Method 1
# Leap ← +=0◿4:-=0◿100:=0◿400..
# Method 2
Leap ← ¬/=±◿4_100_400
# create an array of mod with 4, 100, 400
# get sign of the results (1 for pos, 0 for zero)
# reduce for comparison and not the reduction