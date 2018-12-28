# -*- coding: utf-8 -*-


class Solution:
    """
    @param words: the given list of words
    @return: the number of different transformations among all words we have
    """

    def uniqueMorseRepresentations(self, words):
        # Write your code here
        reduce = [
            ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
            ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
            "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
        ]
        generate_set = set()
        for index, string_ in enumerate(words):
            temp_arr = ''
            for j, char_ in enumerate(string_):
                z = ord(char_) - 97  # 所在编码序列位置
                temp_arr += reduce[z]
            generate_set.update([temp_arr])  # 使用集合会自动去重
        len_ = len(generate_set)
        print(len_)
        return len_
