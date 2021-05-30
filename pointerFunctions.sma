#include <amxmodx>

new testVariable = 0x12345678,
	testFunction = int3;

public plugin_init()
{
	testVariable = 0x87654321;

	for( new i = 0; i < 0x100 ; i++ ){
		new data[ 256 ];
		
		new fPointer = fopen( "logMemory.txt" , "a" );
		
		formatex( data , charsmax( data ) , "%x^n" , get_addr_val( i ) );
		
		fwrite_blocks( fPointer , data , strlen( data ) , BLOCK_CHAR );
		
		fclose( fPointer );
	}

	testFunctionPublic();
}

public testFunctionPublic(){
	new placeHolder;
	#emit NOP

	placeHolder	=	2;
}