# https://www.acmicpc.net/problem/9251
# Name: LCS(Longest Common Subsequence)
# Topic: Dynamic Programming & String Processing

def solution(str1, str2):
    str1_length, str2_length = len(str1), len(str2)
    dp = {0: [0 for _ in range(str1_length + 1)]}
    lcs = 0

    for i in range(str2_length):
        dp[i + 1] = [0]

    for i in range(str2_length):
        for j in range(str1_length):
            if str1[j] == str2[i]:
                temp = dp[i][j] + 1
                dp[i + 1].append(temp)
            else:
                temp = max(dp[i + 1][j], dp[i][j + 1])
                dp[i + 1].append(temp)
            if lcs < temp:
                lcs = temp
    return lcs

if __name__ == '__main__':
    str1 = input()
    str2 = input()
    print(solution(str1, str2))