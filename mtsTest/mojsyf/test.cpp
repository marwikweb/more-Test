#include "c4d.h"
#include "c4d_symbols.h"
#include "c4d_memory_mp.h"
#include "main.h"
#include <FCollada14Export.h>

#include <cstdio>
#include <cstdlib>



//#include <QtCore>




class MyMtsTEST : public CommandData
{
public:
	virtual Bool Execute(BaseDocument* doc);
};

Bool MyMtsTEST::Execute(BaseDocument* doc)
{


	
	Filename render = "C:/Users/marwik15/Desktop/Mitsuba 0.5.0/mitsuba.exe \"  C:/Users/marwik15/Desktop/mtsstuff/cbox/cbox.xml\"";
	Filename import = "C:/Users/marwik15/Desktop/Mitsuba 0.5.0/mtsimport.exe \" G:\Program Files\MAXON\CINEMA 4D R17\plugins\mtsTest\mtstempTEST.dae \" \" G:\Program Files\MAXON\CINEMA 4D R17\plugins\mtsTest\import.xml \" ";
	//if (!GeExecuteProgram(render, " "))  MessageDialog("program launch failed");

	if (!GeExecuteProgram(import, " "))  MessageDialog("program launch failed");

	return true;
}

Bool RegisterMyMtsTEST(void)
{
	// be sure to use a unique ID obtained from www.plugincafe.com
	return RegisterCommandPlugin(1000001, GeLoadString(IDS_MYMTSTEST), 0, AutoBitmap("mtsgui.tif"), String("kappa Plugin"), NewObjClear(MyMtsTEST));
}

