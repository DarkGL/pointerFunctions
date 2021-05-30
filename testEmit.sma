#include <amxmodx>

#include "pointersFunctions.inc"

public plugin_init(){
	register_plugin( "testEmit" , "testEmit" , "testEmit" );

	new PointerFunc: funcTestPointer = getPointerFunc( "funcTest" );

	new PointerFunc: funcTestPointer2 = getPointerFunc( "funcTest2" );

	//execFunc( funcTestPointer , 1 );
	//execFunc( funcTestPointer2 );

	log_amx( "%d | %d" , funcTestPointer , funcTestPointer2 );

	//funcTest2();
}

public funcTest( variable ){
	log_amx( "funcTest: %d" , variable );
}

public funcTest2(){
	log_amx( "funcTest2" );
}