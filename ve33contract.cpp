#pragma once

#include "ve33contract.hpp"
#include "functions.cpp"
#include "on_notify.cpp"


ACTION ve33contract::initstate(){
	eosio::check(!state_s.exists(), "state already exists");

	state s{};
	s.last_vote_time = 0;
	state_s.set(s, _self);
}