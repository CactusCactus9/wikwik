#ifndef ITER_HPP
#define ITER_HPP

template	<typename T, typename Funct>
void	iter(T *arr, int len, Funct function){
	for (int i = 0; i < len; i++){
		function(arr[i]);
	}
}
#endif