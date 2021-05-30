#if defined _pointersFunc_included
	#endinput
#endif

#define _pointersFunc_included

stock PointerFunc: getPointerFunc( funcName[] ){
	new idFunc	=	funcidx( funcName );

	if( idFunc == -1 ){
		return PointerFunc: 0;
	}

	new PointerFunc: pointer = PointerFunc: 0;

	#emit LCTRL   		1
	//#emit NEG
	//#emit ADD.C 		32
	#emit STOR.S.pri  	pointer
	//#emit LREF.S.pri    pointer
	//#emit STOR.S.pri  	pointer

	/*#emit LCTRL 1
	#emit NEG
	#emit ADD
	#emit LOAD.S.alt  idFunc
	#emit SHL.C.alt   3
	#emit ADD
	#emit STOR.S.pri  pointer
	#emit LREF.S.pri  pointer
	#emit STOR.S.pri  pointer*/

	return pointer;
}

stock execFunc( PointerFunc: funcPointer , ... ){
	
	static const STATIC_ARGS = 1;
	static const BYTES_PER_CELL = 4;

	new n = (numargs() - STATIC_ARGS) * BYTES_PER_CELL;
    
    if ( n ){
        new arg_start,
            arg_end;
        
        #emit CONST.alt        8
        #emit LCTRL          5
        #emit ADD
        #emit STOR.S.pri        arg_start
        
        #emit LOAD.S.alt        n
        #emit ADD
        #emit STOR.S.pri        arg_end
        
        do
        {
            #emit LOAD.I
            #emit PUSH.pri
            arg_end -= BYTES_PER_CELL;
            #emit LOAD.S.pri      arg_end
        }
        while (arg_end > arg_start);
        
        #emit PUSH.S          n

        #emit LCTRL      6
		#emit ADD.C      28
		#emit PUSH.pri
		#emit LOAD.S.pri funcPointer
		#emit SCTRL      6

        n += BYTES_PER_CELL;
        #emit LCTRL          4
        #emit LOAD.S.alt        n
        #emit ADD
        #emit SCTRL          4
    }
}
