//============================================================================
// Name        : main.cpp
// Author      : Rahman Salim Zengin
// Version     :
// Copyright   : rsz@gufatek.com
// Description :
//============================================================================

#include <tuple>
#include <iostream>
#include <string>
#include <stdexcept>
#include <type_traits>
#include <vector>
#include "cmp_chain.hpp"


std::tuple<double, char, std::string> get_student(int id) {
	if (id == 0)
		return std::make_tuple(3.8, 'A', "Lisa Simpson");
	if (id == 1)
		return std::make_tuple(2.9, 'C', "Milhouse Van Houten");
	if (id == 2)
		return std::make_tuple(1.7, 'D', "Ralph Wiggum");
	throw std::invalid_argument("id");
}


template<typename Tuple, int ElemInx>
class Print_tuple_elements {
public:
	void operator ()(const Tuple & tuple) {
		Print_tuple_elements<Tuple, ElemInx - 1> {}(tuple);
		std::cout << std::get<ElemInx>(tuple) << " ";
	}
};

template<typename Tuple>
class Print_tuple_elements<Tuple, 0> {
public:
	void operator ()(const Tuple & tuple) {
		std::cout << std::get<0>(tuple) << " ";
	}
};

template<typename... Types>
void print_tuple(const std::tuple<Types...> & tuple) {
	Print_tuple_elements<std::tuple<Types...>, std::tuple_size<std::tuple<Types...>>::value - 1> {}(tuple);
	std::cout << std::endl;
}

int main() {

	for (int inx = 0; inx < 20; ++inx) {
		if (cmp::chain < 5 <= inx < 15)
			std::cout << inx << " ";
	}
	std::cout << std::endl;

	std::vector<std::string> words { "aback", "abaft", "abandon", "abandoned",
			"abandonment", "abase", "abash", "abashment", "abate", "abatement",
			"abbey", "abbreviate", "abbreviatio", "abdicate", "abdomen",
			"abduct", "abduction", "abecedarian", "aberrant", "aberrated",
			"aberration", "aberrationa", "abet", "abetment", "abettor",
			"abeyance", "abhor", "abhorrence", "abhorrent", "abidance", "abide",
			"abiding", "ability", "abject", "abjection", "abjectly", "abjure",
			"ablaze", "able", "ably", "abnegate", "abnegation", "abnormal",
			"abnormality", "abode", "aboil", "abolish", "abolishment",
			"abolition", "abominable", "abominate", "abomination", "aboriginal",
			"aborigine", "aborning", "abort", "abortion", "abortive", "abound",
			"abounding", "about", "above", "abracadabra", "abrade", "abrasion",
			"abrasive", "abreast", "abridge", "abridgment", "abrogate",
			"abrogation", "abrupt", "abruptly", "abscond", "absence", "absent",
			"absentminde", "absolute", "absolutenes", "absolution",
			"absolutism", "absolve", "absorb", "absorbed", "absorbent",
			"absorbing", "absorption", "abstain", "abstainer", "abstemious",
			"abstentious", "abstinence", "abstinent", "abstract", "abstracted",
			"abstraction", "abstruse", "absurd", "absurdity", "abubble",
			"abundance", "abundant", "abuse", "abusive", "abut", "abutting",
			"abuzz", "abysm", "abysmal", "abyss", "academe", "academic",
			"academy", "accede", "accelerate", "accent", "accentuate",
			"accentuation", "accept", "acceptability", "acceptable",
			"acceptably", "access", "accessible", "accession", "accessorial",
			"accessory", "accident", "accidental", "acclaim", "acclamation",
			"acclimate", "acclimation", "acclimatization", "acclimatize",
			"acclivity", "accolade", "accommodate", "accommodating",
			"accommodation", "accommodative", "accompaniment", "accompany",
			"accompanying", "accomplice", "accomplish", "accomplished",
			"accomplishment", "accord", "accordance", "accordant",
			"accordingly", "accouchement", "account", "accountable",
			"accounting", "accoutre", "accoutrement", "accredit",
			"accreditation", "accrete", "accretion", "accretive", "accrual",
			"accumulate", "accumulating", "accumulation", "accumulative",
			"accuracy", "accurate", "accurateness", "accursed", "accuse",
			"accustom", "accustomed", "ace", "acerb", "acerbic", "acerbity",
			"ache", "achievable", "achieve", "achievement", "aching",
			"achingly", "achy", "acid", "acidic", "acidity", "acidness",
			"acidulous", "acknowledge", "acknowledgment", "acme", "acolyte" };

	for (auto& x : words) {
		if (cmp::chain < "abb" <= x < "abe")
			std::cout << x << " ";
	}
	std::cout << std::endl;

}
