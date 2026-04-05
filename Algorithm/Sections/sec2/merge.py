def merge(a, p, q, r):
	n1 = q - p + 1
	n2 = r - q

	# create temp arrays
	L = [0] * (n1)
	R = [0] * (n2)

	# Copy data to temp arrays L[] and R[]
	for i in range(0, n1):
		L[i] = a[p + i]

	for j in range(0, n2):
		R[j] = a[q + j+1]

	# Merge the temp arrays back into a[p..r]
	i = 0	 
	j = 0	 
	k = p	 
    
	while i < n1 and j < n2:
		if L[i] <= R[j]:
			a[k] = L[i]
			i += 1
		else:
			a[k] = R[j]
			j += 1
		k += 1

	# Copy the remaining elements of L[], if there
	# are any
	while i < n1:
		a[k] = L[i]
		i += 1
		k += 1

	# Copy the remaining elements of R[], if there
	# are any
	while j < n2:
		a[k] = R[j]
		j += 1
		k += 1

# p is for left index and r is right index of the
# sub-array of a to be sorted


def mergeSort(a, p, r):
	if p < r:

		# Same as (l+r)//2, but avoids overflow for
		q = p+ (r-p)//2
		# Sort first and second halves
		mergeSort(a, p, q)
		mergeSort(a, q+1, r)
		merge(a, p, q, r)
  
# test code
a = [12, 11, 13, 5, 6, 7]
n = len(a)
print(a)

print("\n")

mergeSort(a, 0, n-1)
print(a)




