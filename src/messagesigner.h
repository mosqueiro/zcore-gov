// Copyright (c) 2014-2017 The Dash Core developers
// Copyright (c) 2018 The ZCore Core developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ZCORE_MESSAGE_SIGNER
#define ZCORE_MESSAGE_SIGNER

#include "key.h"

class CMessageSigner {
public:
    /// Set the private/public key values, returns true if successful
    static bool GetKeysFromSecret(const std::string strSecret, CKey& keyRet, CPubKey& pubkeyRet);
    /// Sign the message, returns true if successful
    static bool SignMessage(const std::string strMessage, std::vector<unsigned char>& vchSigRet, const CKey key);
    /// Verify the message signature, returns true if succcessful
    static bool VerifyMessage(const CPubKey pubkey, const std::vector<unsigned char>& vchSig, const std::string strMessage, std::string& strErrorRet);
};

class CHashSigner {
public:
    /// Sign the hash, returns true if successful
    static bool SignHash(const uint256& hash, const CKey key, std::vector<unsigned char>& vchSigRet);
    /// Verify the hash signature, returns true if succcessful
    static bool VerifyHash(const uint256& hash, const CPubKey pubkey, const std::vector<unsigned char>& vchSig, std::string& strErrorRet);
};


#endif