/*
 * cmp_chain.hpp
 *
 *  Created on: 13 Eki 2016
 *      Author: RSZ
 */

#ifndef CMP_CHAIN_HPP_
#define CMP_CHAIN_HPP_

#include <tuple>

namespace cmp {


template<std::size_t BeginInx, std::size_t EndInx, typename... Types>
class Implement {
public:
	static constexpr inline bool comparison(const std::tuple<Types...>& tuple) {
		return (std::get<BeginInx + 2>(tuple) == "<" ?
				std::get<BeginInx + 1>(tuple) < std::get<BeginInx + 3>(tuple) :
				std::get<BeginInx + 1>(tuple) <= std::get<BeginInx + 3>(tuple)) &&
				Implement<BeginInx + 2, EndInx, Types...>::comparison(tuple);
	}
};

template<std::size_t EndInx, typename... Types>
class Implement<EndInx, EndInx, Types...> {
public:
	static constexpr inline bool comparison(const std::tuple<Types...>& tuple) {
		return true;
	}
};

template<typename... Types>
class cmp_chain {
public:
	cmp_chain() : operands(std::tuple<> {}) {}
	cmp_chain(std::tuple<Types...> tuple) : operands(tuple) {}

	std::tuple<Types...> operands;

	template<typename RType>
	constexpr inline cmp_chain<Types..., std::string, RType> operator <(RType&& rhs) {
		return cmp_chain<Types..., std::string, RType>
		{std::tuple_cat(operands, std::forward_as_tuple("<", rhs))};
	}

	template<typename RType>
	constexpr inline cmp_chain<Types..., std::string, RType> operator <=(RType&& rhs) {
		return cmp_chain<Types..., std::string, RType>
		{std::tuple_cat(operands, std::forward_as_tuple("<=", rhs))};
	}

	constexpr inline operator bool() {
		return Implement<0, sizeof...(Types) - 2, Types...>::comparison(operands);
	}
};

cmp_chain<> chain {};

} /* namespace cmp */

#endif /* CMP_CHAIN_HPP_ */
