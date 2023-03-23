/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */

class Solution {
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        vector<string> ret;
        unordered_map<string, int> m;
        queue<string> q;
        q.push(startUrl);
        m[startUrl] = 1;
        string base = "";
        int counter = 0;
        for(char i:startUrl){
            if(i == '/'){
                counter++;
            }
            if(counter == 3){
                break;
            }
            base+=i;
        }
        while(!q.empty()){
            string tmp = q.front();
            ret.push_back(tmp);
            q.pop();
            vector<string> v = htmlParser.getUrls(tmp);
            for(string i:v){
                
                counter = 0;
                string tmp2 = "";
                for(char j:i){
                    if(j == '/'){
                        counter++;
                    }
                    if(counter == 3){
                        break;
                    }
                    tmp2 += j;
                }
                
                if(m[i] == 0 && tmp2 == base){
                    q.push(i);
                    m[i] = 1;
                }
            }
            //cout << endl;
        }
        return ret;
    }
};
