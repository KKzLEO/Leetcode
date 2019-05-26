int numUniqueEmails(vector<string>& emails) {
        vector<string> answer;
        string localName;
        string domainName;
        
        for(int i=0;i<emails.size();i++){
            for(int j=0;j<emails[i].length();j++){
                localName = emails[i].substr(0, emails[i].find('@'));
                domainName = emails[i].substr(emails[i].find('@')+1, emails[i].length());
                
                localName.replace(localName.begin(),localName.end(),'.','\0');
                localName = localName.substr(0,localName.find('+'));
                
                if(std::find(answer.begin(),answer.end(),localName+'@'+domainName) == answer.end()){
                    answer.push_back(localName+'@'+domainName);
                }
            }
        }
        return answer.size();
    }