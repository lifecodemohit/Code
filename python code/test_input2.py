import sys
 
def main():
	n, k = map(int, sys.stdin.readline().split())
	count = 0
	for i in sys.stdin:
		if int(i) % k == 0:
			count += 1
	print '%d' % count
 
main()