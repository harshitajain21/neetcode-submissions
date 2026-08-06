class Solution {
public:

//["neet","code", "loves",]

    string encode(vector<string>& strs) {
        
        string sf;
        for(auto &word:strs){
            sf.append(to_string(word.size()));
            sf.push_back('#');
            sf.append(word);
        }
        return sf;

        //"4#neet4#code5#loves"
    }

    vector<string> decode(string s) {
        vector<string> res;
        string ss;
        int i=0;

        while(i<s.size()){

            int length = 0;

            while (s[i] != '#') {
                length = length * 10 + (s[i] - '0'); //ex: 12#helloworld!!
                i++;
            }

            i++; // skip '#'

            res.push_back(s.substr(i, length));

            i += length;}
        return res;
    }
    
};
