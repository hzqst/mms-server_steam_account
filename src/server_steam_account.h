/**
 * vim: set ts=4 sw=4 tw=99 noet :
 * ======================================================
 * Metamod:Source Sample Plugin
 * Written by AlliedModders LLC.
 * ======================================================
 *
 * This software is provided 'as-is', without any express or implied warranty.
 * In no event will the authors be held liable for any damages arising from 
 * the use of this software.
 *
 * This sample plugin is public domain.
 */

#ifndef _INCLUDE_METAMOD_SOURCE_STUB_PLUGIN_H_
#define _INCLUDE_METAMOD_SOURCE_STUB_PLUGIN_H_

#include <ISmmPlugin.h>
#include <sh_vector.h>

#include <steam/steam_api_common.h>
#include <steam/isteamuser.h>

#define MAX_ACCOUNT_TOKEN_LENGTH 32

class ServerSteamAccount : public ISmmPlugin, public IMetamodListener
{
public:
	bool Load(PluginId id, ISmmAPI *ismm, char *error, size_t maxlen, bool late);
	bool Unload(char *error, size_t maxlen);
	void AllPluginsLoaded();
	bool Pause(char *error, size_t maxlen);
	bool Unpause(char *error, size_t maxlen);

public: // SourceHooks.
	void OnGameServerSteamAPIActivated();
	void OnGameServerSteamAPIDeactivated();

private: // Commands.
	CON_COMMAND_MEMBER_F(ServerSteamAccount, "sv_setsteamaccount", OnSetSteamAccountCommand, "Set game server account token to use for logging in to a persistent game server account", FCVAR_LINKED_CONCOMMAND);

private: // Game server methods.
	bool ProcessCommandLineAccount();
	bool AuthorizeGameServer(ISteamGameServer *pGameServer);

public:
	const char *GetAuthor();
	const char *GetName();
	const char *GetDescription();
	const char *GetURL();
	const char *GetLicense();
	const char *GetVersion();
	const char *GetDate();
	const char *GetLogTag();

private:
	char m_sAccount[MAX_ACCOUNT_TOKEN_LENGTH + 1] = "\0";

	bool m_bWantAuthorize = false;

	ISteamGameServer *m_pSteamGameServer;
};

extern ServerSteamAccount g_aServerSteamAccount;

PLUGIN_GLOBALVARS();

#endif //_INCLUDE_METAMOD_SOURCE_STUB_PLUGIN_H_
