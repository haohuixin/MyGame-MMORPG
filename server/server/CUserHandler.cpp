#include "stdafx.h"
#include "CUserHandler.h"

#include "CServer.h"

CUserHandler::CUserHandler( Context * pcContext ) : Object( pcContext )
{
}

CUserHandler::~CUserHandler()
{
}

BOOL CUserHandler::LoadUser( CUser * pUser, String strAccountName )
{
	if( pUser )
	{
		//Inicializar a classe do usu�rio
		pUser->Init( strAccountName );

		if( GAME_SERVER )
		{
			VectorBuffer cMessage;

			/*
			 * ESCREVER OS PERSONAGENS ENCONTRADOS DAQUELA CONTA (NICK,LEVEL,CLASSE,MAPA)
			 */

			SERVERNETWORK->SendPacket( pUser->GetConnection(), PKTHDR_GameServerData, cMessage );
		}
	}

	return TRUE;
}

BOOL CUserHandler::AddUser( Connection * pConnection )
{
	Hash_Users::Iterator i = vUsers.Find( pConnection );

	//Usu�rio foi encontrado? Ent�o quer dizer que j� tem um usu�rio com est� conex�o, apenas retornar FALSE
	if( i != vUsers.End() )
		return FALSE;

	//Caso contr�rio, adicionar o usu�rio no servidor
	SharedPtr<CUser> pUser( new CUser( context_, pConnection ) );
	vUsers[pConnection] = pUser;
}

void CUserHandler::DelUser( Connection * pConnection )
{
	Hash_Users::Iterator i = vUsers.Find( pConnection );

	//Usu�rio foi encontrado? Ent�o deletar
	if( i != vUsers.End() )
		vUsers.Erase( pConnection );
}