// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2015 The Bitcredit Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCREDIT_RPCBASENODE_H
#define BITCREDIT_RPCBASENODE_H

#include <univalue.h>

UniValue basenodelist(const UniValue& params, bool fHelp);
UniValue basenode(const UniValue& params, bool fHelp);

#endif // BITCREDIT_RPCBASENODE_H
