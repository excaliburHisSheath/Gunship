#include "Spectacle.h"

void MakePlayer( GameObject& player, GameObject& target )
{
	player.AddMesh( "playerMesh", "ColourCube" );
	player.SetPosition( 0.0f, 0.0f, 0.0f );
	player.AddBehavior(
			[ &target ]( GameObject& gameObject, const Input& input )
			{
				static float playerSpeed = 0.05f;

				if ( input.KeyPressed( SDLK_w ) )
				{
					gameObject.Translate( 0.0f, playerSpeed, 0.0f );
				}
				if ( input.KeyPressed( SDLK_a ) )
				{
					gameObject.Translate( -playerSpeed, 0.0f, 0.0f );
				}
				if ( input.KeyPressed( SDLK_s ) )
				{
					gameObject.Translate( 0.0f, -playerSpeed, 0.0f );
				}
				if ( input.KeyPressed( SDLK_d ) )
				{
					gameObject.Translate( playerSpeed, 0.0f, 0.0f );
				}

				float xTrans = input.AxisValue( 0, SDL_CONTROLLER_AXIS_LEFTX );
				float yTrans = input.AxisValue( 0, SDL_CONTROLLER_AXIS_LEFTY );

				gameObject.Translate( xTrans * playerSpeed, yTrans * -playerSpeed, 0.0f );

				gameObject.LookAt( target );
			} );

	target.AddMesh( "targetMesh", "ColourCube" );
	target.SetPosition( 0.0f, 2.0f, 0.0f );
	target.SetScale( 0.25f, 0.25f, 0.25f );

	target.AddBehavior(
			[ &player ]( GameObject& gameObject, const Input& input )
			{
				static float offset = 2.0f;

				Ogre::Vector3 pos = player.Position();
				float xTrans = input.AxisValue( 0, SDL_CONTROLLER_AXIS_RIGHTX );
				float yTrans = input.AxisValue( 0, SDL_CONTROLLER_AXIS_RIGHTY );
				gameObject.SetPosition( pos.x + xTrans * offset, pos.y + -yTrans * offset, pos.z + 0.0f );
			} );
}