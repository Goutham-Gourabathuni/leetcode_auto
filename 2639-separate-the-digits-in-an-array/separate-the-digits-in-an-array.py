class Solution:
    def separateDigits(self, nums: List[int]) -> List[int]:
        strings = [str(x) for x in nums]
        sentence = "".join(strings)
        char_list=[]
        for char in sentence:
            char_list.append(char)
        new_list = [int(x) for x in char_list]
        return new_list 

        


        