#ifndef _freeman_print_h_
#define _freeman_print_h_

#include<iostream>
#include<vector>

namespace Freeman{
	template<typename T>
		void print(std::vector<T>& v){
			for(int i=0;i<v.size();++i)
				std::cout<<v[i]<<"  ";
			std::cout<<std::endl;
		}

	template<typename T>
		void print(std::vector<std::vector<T> >& vv){
			for(int i=0;i<vv.size();++i){
				for(int j=0;j<vv[i].size();++j){
					std::cout<<vv[i][j]<<"  ";
				}
				std::cout<<std::endl;
			}
		}
}
#endif
