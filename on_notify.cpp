#pragma once

void ve33contract::receive_wax_transfer(const name& from, const name& to, const asset& quantity, const std::string& memo){
	const name tkcontract = get_first_receiver();

    check( quantity.amount > 0, "Must redeem a positive quantity" );
    check( quantity.amount < MAX_ASSET_AMOUNT, "quantity too large" );

    if( from == get_self() || to != get_self() ){
    	return;
    }

    check( quantity.symbol == WAX_SYMBOL, "was expecting WAX token" );

    //redundant check which isnt necessary when not using catchall notification handler
    check( tkcontract == WAX_CONTRACT, "first receiver should be eosio.token" );

    std::vector<std::string> words = get_words(memo);

    if( words[1] == "revenue"){



    	return;
    }

}