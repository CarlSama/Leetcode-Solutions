/*
 * 1) recursion method
 *	  为记录中间状态.
 *
 * 2) dynamic method
 *    match[si][pi] means 0~si-1 and 0~pi-1
 *
 *           when pi == *
 *				if(pi-1 == .){
 *					// used 0
 *					match[si][pi-2]
 *					//use 1 or more
 *					match[si]pi-1]
 *					match[si-1][pi-2]
 *				}else{
 *					
 *					
 *    pi 
 *           when pi != *  , same as ( match[si-1][pi-1] && si == pi )
 *
 *           when pi == . , same as match[si-1][pi-1]
 *
 *	3) 自动机器
 */
