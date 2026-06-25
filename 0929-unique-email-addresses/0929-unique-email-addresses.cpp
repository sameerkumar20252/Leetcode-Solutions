
      class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string>email;
        
        for (auto &itr : emails) {
            string local_name=itr.substr(0,itr.find('@'));
            string domain_name=itr.substr(itr.find('@')); 
            string m_local_name=modify(local_name);
            
            string final_email=m_local_name + domain_name;
            email.insert(final_email); 
        }
        
        return email.size();
    }
    
    string modify(string s1) {
        string s2="";
        for (int i=0;i<s1.length();i++) {
            if (s1[i]=='.') {
                continue; 
            }
            else if (s1[i]=='+') {
                break;
            }
            else {
                s2+=s1[i];
            }
        }
        return s2;
    }
};