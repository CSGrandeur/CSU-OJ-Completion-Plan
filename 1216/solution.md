裸的01字典树
- 正解：
    - 每个数用二进制数表示，用32位的0、1数组（高位在前）储存到01字典树中。
    - 对于每次询问q，将q也表示成01串，从高位到低位每次贪心的顺着字典树向下找相反的结点（0找1，1找0），
    因为这样可以保证让两个数的异或值尽可能地大（所以一定要从高位向下找）。