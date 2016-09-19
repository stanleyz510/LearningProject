#!/usr/bin/python
# coding=utf-8
import logging
logging.basicConfig()
logger = logging.getLogger(__name__)
logger.setLevel("DEBUG")
class Solution(object):
    def preProcess(self, s):
        """
        Add the '#' seperator to input string s, preprocess for finding logest Palindrome algorithm
        :type s: str
        :rtype str
        """
        charslist = []
        # splite string to char sequence
        for c in s:
            charslist.append(c)
        return "#" + "#".join(charslist) + "#"
    
    def expandPalindrome(self, s, index, knownRadius):
        radius = knownRadius + 1
        while( index - radius >= 0 and index + radius < len(s) and s[index-radius] == s[index+radius]):
            radius += 1
        return radius - 1

    def longestPalindrome(self, s):
        """
        Find the longest Palindrome substring
        Adopt Manacher’s algorithm(http://articles.leetcode.com/longest-palindromic-substring-part-ii/).
        :type s: str
        :rtype str
        """

        # step 1: preprocess, to: 1.add '#' to combine aa and aba condition; 2.to generate an helper list to adopt Manacher's Algorithm'  
        ps = self.preProcess(s)
        p = [0] * len(ps)

        logger.debug("ps: %s", str(ps))
        
        # step 2: generate the list p
        i = c = r = oi = 0 # index, center, radius of current palindrome window, the opposite element's index' of i(in the current palindrome window)
        for i in range(len(ps)):
           
            # calculate the opposite index. could be negtive, which is fine
            oi = c - (i - c) 

            # the core part of algorithm, please see above link for detail
            if (oi > 0 and i + p[oi] < c + r):
                p[i] = p[oi]
            else:
                knownRadius = min(p[oi], oi - (c - r))
                p[i] = self.expandPalindrome(ps, i, knownRadius)
                if p[i] + i > c + r:
                    c = i
                    r = p[i]

            logger.debug(" - i: %d \t c: %d \t r: %d \t oi: %d \t p[i]: %d" % (i, c, r, oi, p[i]))

        logger.debug("p: %s", str(p))
            
        # step 3: get the max of list, sub it from original and output
        maxIndex = p.index(max(p))
        result = ps[maxIndex - p[maxIndex] : maxIndex + p[maxIndex] + 1]
        result = "".join(result.split("#"))
        return result

s = Solution()
print(s.longestPalindrome("bb"))