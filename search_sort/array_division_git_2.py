n, k = map(int, input().split())
nums = list(map(int, input().split()))


def can_divide_arrays(max_sum: int) -> bool:
	"""
	Checks if it is possible to divide nums into k subarrays with each
	each subarray having a maximum sum of max_sum

	:param max_sum: The maximum sum of each subarray
	:return: If it is possible to divide nums with the above conditions.
	"""
	num_subarrays = 0
	cur_subarr_sum = 0
	for num in nums:
		if cur_subarr_sum + num <= max_sum:
			cur_subarr_sum += num
		elif num <= max_sum:
			num_subarrays += 1
			cur_subarr_sum = num
			if num_subarrays > k:
				return False
		else:
			return False

	# last sub seq is not counted in the loop
	num_subarrays += cur_subarr_sum > 0

	return num_subarrays <= k


left, right = max(nums), sum(nums)

while left < right:
	mid = (left + right) // 2
	if can_divide_arrays(mid):
		right = mid
	else:
		left = mid + 1

print(left)