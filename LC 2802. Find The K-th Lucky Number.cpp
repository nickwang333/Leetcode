class Solution {
public:
    string kthLuckyNumber(int k)
{
	string out{};
	++k;
	for( ; k!=1; k/=2)
		out.push_back(k&1 ? '7' : '4');
	reverse(begin(out), end(out));
	return out;
}

};
