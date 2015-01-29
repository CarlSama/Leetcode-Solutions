#include<iostream>
#include<string>

using namespace std;

void pop_back(string &res){
	if(res.empty() || res == "/")
		return ;
	int i;
	for(i = res.size()-1;i>=0 && res[i] != '/' ;i--){
	}

	res.erase(i,res.size()-i);
}

void safeSlash(string &res){
	int i = res.size()-1;
	while(i>=0 && res[i] == '/'){
		res.pop_back();	
	}
	res += '/';
}

string	simplifyPath(string path){
	int len = path.size();

	string res ;
	for(int i=0;i<len;i++){
		if(path[i] == '/'){
			if(i+1<len){
				if(path[i+1] == '.'){
					if(i+2<len){
						if(path[i+2] == '.'){
							if(i+3<len){
								if(path[i+3] == '/'){
									if(res.size()==0)
										res = "/";
									else
										pop_back(res);
									i+= 2;
								}else{
									safeSlash(res);
								}
							}else{
								if(res.size()==0)
									res = "/";
								else
									pop_back(res);
								i += 2;
							}
						}else if(path[i+2] == '/'){
							i++;
						}else{
							res += path[i];
						}
					}else{
						if(res.size()==0)
							res = "/";
						i++;
					}
				}else{
					safeSlash(res);
				}
			}else{
				safeSlash(res);
			}
		}else{
			res += path[i];
		}
	}

	if(res.back() == '/' && res.size() > 1)
		res.pop_back();

	return res;
}

int main(){
	cout<<simplifyPath("/home/")<<endl;
	cout<<simplifyPath("/a/./b/../../c/")<<endl;
	cout<<simplifyPath("/...")<<endl;
	cout<<simplifyPath("/..")<<endl;
	cout<<simplifyPath("/.")<<endl;
	cout<<simplifyPath("/")<<endl;
	cout<<simplifyPath("////")<<endl;
	cout<<simplifyPath("/l///././//../../pCD/.././././//g///././URW//")<<endl;
	cout<<simplifyPath("/pKpGC/.././l/U/../././AM/../././//..///..///ov/../..///zy/././k//")<<endl;
	cout<<simplifyPath("/.hi")<<endl;
	return 0;

}


