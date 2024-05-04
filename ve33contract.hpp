#pragma once
#define CONTRACT_NAME "ve33contract"

#include <eosio/eosio.hpp>
#include <eosio/print.hpp>
#include <eosio/asset.hpp>
#include <eosio/system.hpp>
#include <eosio/symbol.hpp>
#include <eosio/action.hpp>
#include <string>
#include <eosio/crypto.hpp>
#include <eosio/transaction.hpp>
#include <eosio/singleton.hpp>
#include <cmath>
#include "tables.hpp"
#include "structs.hpp"
#include "constants.hpp"
#include <limits>

using namespace eosio;


CONTRACT ve33contract : public contract {
	public:
		using contract::contract;
		ve33contract(name receiver, name code, datastream<const char *> ds):
		contract(receiver, code, ds),
		state_s(receiver, receiver.value)
		{}

		//Main Actions
		ACTION initstate();

		//Notifications
		[[eosio::on_notify("eosio.token::transfer")]] void receive_wax_transfer(const name& from, const name& to, const asset& quantity, const std::string& memo);

	private:

		//Singletons
		state_singleton state_s;


		//Functions
		std::vector<std::string> get_words(std::string memo);
		uint64_t now();
		void transfer_tokens(const name& user, const asset& amount_to_send, const name& contract, const std::string& memo);

};



