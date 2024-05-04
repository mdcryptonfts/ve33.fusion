#pragma once


struct [[eosio::table, eosio::contract(CONTRACT_NAME)]] state {
  uint64_t          last_vote_time;

  EOSLIB_SERIALIZE(state, (last_vote_time))
};
using state_singleton = eosio::singleton<"state"_n, state>;