#include "stdafx.h"
#include "CGame.h"

CGame * CGame::pcInstance = NULL;

URHO3D_DEFINE_APPLICATION_MAIN( CGame )

CGame::CGame( Context * pcContext ) : Application( pcContext )
{
	//Instantiate This
	pcInstance = this;

	INI::Parser::RegisterObject( pcContext );
	ProcSky::RegisterObject( pcContext );

	pGameConfig		= new CGameConfig( pcContext, "game.ini" );
	pGameNetwork	= new CGameNetwork( pcContext );
	pGameManager	= new CGameManager( pcContext );
	pGameHandler	= new CGameHandler( pcContext );
}

void CGame::Setup()
{
	if( GAMECONFIG->Read() )
	{
		//Configurações de inicialização da Aplicação
		engineParameters_[EP_WINDOW_TITLE] = "Game";
		engineParameters_[EP_FULL_SCREEN] = !GAMECONFIG->Get().bWindowed;
		engineParameters_[EP_HEADLESS] = false;
		engineParameters_[EP_SOUND] = false;
		engineParameters_[EP_WINDOW_RESIZABLE] = true;
		engineParameters_[EP_WINDOW_WIDTH] = GAMECONFIG->Get().iWindowWidth;
		engineParameters_[EP_WINDOW_HEIGHT] = GAMECONFIG->Get().iWindowHeight;
		engineParameters_[EP_MULTI_SAMPLE] = 4;
		engineParameters_[EP_RESOURCE_PATHS] = "Data;";

		//Setar o mouse como visivel
		GetSubsystem<Input>()->SetMouseVisible( true );
	}
}

void CGame::Start()
{
	Application::Start();

	//Registrar Eventos
	SubscribeToEvent( E_UPDATE, URHO3D_HANDLER( CGame, HandleUpdate ) );
	SubscribeToEvent( E_POSTUPDATE, URHO3D_HANDLER( CGame, HandlePostUpdate ) );
	SubscribeToEvent( E_PHYSICSPRESTEP, URHO3D_HANDLER( CGame, HandlePhysicsPreStep ) );

	//Inicializar Game
	if( !Init() )
		Application::ErrorExit();
}

void CGame::Stop()
{
}

BOOL CGame::Init()
{
	BOOL bRet = TRUE;

	if( !pGameHandler->Init() )
		bRet = FALSE;

	if( !pGameManager->Init() )
		bRet = FALSE;

	if( !pGameNetwork->Init() )
		bRet = FALSE;

	return bRet;
}

void CGame::HandleUpdate( StringHash cEventType, VariantMap & vEventData )
{
	pGameHandler->HandleUpdate( cEventType, vEventData );
	pGameManager->HandleUpdate( cEventType, vEventData );
}

void CGame::HandlePostUpdate( StringHash cEventType, VariantMap & vEventData )
{
	pGameHandler->HandlePostUpdate( cEventType, vEventData );
	pGameManager->HandlePostUpdate( cEventType, vEventData );
}

void CGame::HandlePhysicsPreStep( StringHash cEventType, VariantMap & vEventData )
{
	pGameHandler->HandlePhysicsPreStep( cEventType, vEventData );
	pGameManager->HandlePhysicsPreStep( cEventType, vEventData );
}
