
#include "net.h"
#include "basenodeconfig.h"
#include "chainparams.h"
#include "util.h"

CBasenodeConfig basenodeConfig;

void CBasenodeConfig::add(std::string alias, std::string ip, std::string privKey, std::string txHash, std::string outputIndex) {
    CBasenodeEntry cme(alias, ip, privKey, txHash, outputIndex);
    entries.push_back(cme);
}

bool CBasenodeConfig::read(std::string& strErr) {
    int linenumber = 1;
    boost::filesystem::path pathBasenodeConfigFile = GetBasenodeConfigFile();
	boost::filesystem::ifstream streamConfig(pathBasenodeConfigFile);
    if (!streamConfig.good()) {
		FILE* configFile = fopen(pathBasenodeConfigFile.string().c_str(), "a");
        if (configFile != NULL) {
            std::string strHeader = "# Basenode config file\n"
                          "# Format: alias IP:port basenodeprivkey collateral_output_txid collateral_output_index\n"
                          "# Example: BN01 123.456.789.012:2017 93HaYBVUCYjEMeeH1Y4sBGLALQZE1Yc1K64xiqgX37tGBDQL8Xg 2bcd3c84c84f87eaa86e4e56834c92927a07f9e18718810b92e0d0324456a67c 0\n";
            fwrite(strHeader.c_str(), std::strlen(strHeader.c_str()), 1, configFile);
            fclose(configFile);
        }
        return true; // Nothing to read, so just return
    }

    for(std::string line; std::getline(streamConfig, line); linenumber++)
    {
        if(line.empty()) continue;

        std::istringstream iss(line);
        std::string comment, alias, ip, privKey, txHash, outputIndex;

        if (iss >> comment) {
            if(comment.at(0) == '#') continue;
            iss.str(line);
            iss.clear();
        }

        if (!(iss >> alias >> ip >> privKey >> txHash >> outputIndex)) {
            iss.str(line);
            iss.clear();
            if (!(iss >> alias >> ip >> privKey >> txHash >> outputIndex)) {
                strErr = _("Could not parse basenode.conf") + "\n" +
                        strprintf(_("Line: %d"), linenumber) + "\n\"" + line + "\"";
                streamConfig.close();
                return false;
            }
        }

        if(Params().NetworkIDString() == CBaseChainParams::MAIN) {
            if(CService(ip).GetPort() != 2017) {
                strErr = _("Invalid port detected in basenode.conf") + "\n" +
                        strprintf(_("Line: %d"), linenumber) + "\n\"" + line + "\"" + "\n" +
                        _("(must be 2017 for mainnet)");
                streamConfig.close();
                return false;
            }
        } else if(CService(ip).GetPort() == 2017) {
            strErr = _("Invalid port detected in basenode.conf") + "\n" +
                    strprintf(_("Line: %d"), linenumber) + "\n\"" + line + "\"" + "\n" +
                    _("(2017 could be used only on mainnet)");
            streamConfig.close();
            return false;
        }


        add(alias, ip, privKey, txHash, outputIndex);
    }

    streamConfig.close();
    return true;
}
