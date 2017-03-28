// example code for a menu plugin and multiprocessing

#include "c4d.h"
#include "c4d_symbols.h"
#include "c4d_memory_mp.h"
#include "main.h"
#include <FCollada14Export.h>



class MyMts : public CommandData
{
public:
	virtual Bool Execute(BaseDocument* doc);
};

Bool MyMts::Execute(BaseDocument* doc)
{													  
	const Filename kappa="C:/Users/marwik15/Documents";

	// Export the temporary document as Collada file
	// Collada im - / exporter IDs :
	//ID_COLLADA14_IMPORT 1022315
		// ID_COLLADA14_EXPORT 1022316
		// ID_COLLADA15_IMPORT 1025754
		// ID_COLLADA15_EXPORT 1025755
	

//	GeOpenHTML("https://marwikweb.pl/");

			
	// SaveDocument(doc, kappa, SAVEDOCUMENTFLAGS_EXPORTDIALOG, FORMAT_OBJEXPORT);
	//if (!SaveDocument(doc, GeGetStartupPath() + Filename("tesdddt.cae"), SAVEDOCUMENTFLAGS_0, COLLADA_EXPORT_TRIANGLES))  MessageDialog("error while exporting");

//	if (!SaveDocument(doc, GeGetStartupPath() + Filename("tesdddt.cae"), SAVEDOCUMENTFLAGS_DIALOGSALLOWED | SAVEDOCUMENTFLAGS_SAVEAS | SAVEDOCUMENTFLAGS_EXPORTDIALOG, COLLADA_EXPORT_TRIANGLES))  MessageDialog("expor error");

	if (!SaveDocument(doc, GeGetStartupPath() + Filename("tesdddt.dae"), SAVEDOCUMENTFLAGS_DIALOGSALLOWED |
		SAVEDOCUMENTFLAGS_SAVEAS | SAVEDOCUMENTFLAGS_EXPORTDIALOG, 1022316)){
		MessageDialog("export error");
	}
	else {
		//MessageDialog("export fine");
	//	if (!GeExecuteFile(Filename("‪C:/Users/marwik15/Desktop/1v1_gru_8.mp3"))) MessageDialog("program launch failed");
		if (!GeExecuteProgram(Filename("‪C:/Users/marwik15/Desktop/"),Filename("1v1_gru_8.mp3"))) MessageDialog("program launch failed");
	}
	


	
	//KillDocument(doc);

	//MessageDialog("here still works");
	GePrint("   ");
	GePrint("testowy test testowego pluginu wygada na zaladowany poprawnie ;D");
	GePrint("   ");


	return true;
}

Bool RegisterMyMts(void)
{
	// be sure to use a unique ID obtained from www.plugincafe.com
	return RegisterCommandPlugin(1039026, GeLoadString(IDS_MYMTS), 0, AutoBitmap("mtsgui.tif"), String("kappa Plugin"), NewObjClear(MyMts));
}

