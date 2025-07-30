class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        result = []

        def combination(i, currentValue, totalSum):
            # 1st base case
            if totalSum == target:
                result.append(currentValue.copy())
                return
            # another base case
            if i >= len(candidates) or totalSum > target:
                return

            # there are two options: Pick-up or Not
            # if pickup
            currentValue.append(candidates[i])
            combination(i, currentValue, totalSum + candidates[i])
            currentValue.pop()

            # if not pick-up
            combination(i + 1, currentValue, totalSum)

        combination(0, [], 0)
        return result
