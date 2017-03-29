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

//	GeExecuteFile(Filename("‪C:/Users/marwik15/Desktop/Mitsuba 0.5.0/mtsgui.exe"));
	// Export the temporary document as Collada file								 '
	// Collada im - / exporter IDs :
	//ID_COLLADA14_IMPORT 1022315
		// ID_COLLADA14_EXPORT 1022316
		// ID_COLLADA15_IMPORT 1025754
		// ID_COLLADA15_EXPORT 1025755
	

//	GeOpenHTML("https://marwikweb.pl/");

			
	// SaveDocument(doc, kappa, SAVEDOCUMENTFLAGS_EXPORTDIALOG, FORMAT_OBJEXPORT);
	//if (!SaveDocument(doc, GeGetStartupPath() + Filename("tesdddt.cae"), SAVEDOCUMENTFLAGS_0, COLLADA_EXPORT_TRIANGLES))  MessageDialog("error while exporting");

//	if (!SaveDocument(doc, GeGetStartupPath() + Filename("tesdddt.cae"), SAVEDOCUMENTFLAGS_DIALOGSALLOWED | SAVEDOCUMENTFLAGS_SAVEAS | SAVEDOCUMENTFLAGS_EXPORTDIALOG, COLLADA_EXPORT_TRIANGLES))  MessageDialog("expor error");

	Filename saveDIR = GeGetStartupPath() + "mtsTest/temp/";

	
	GeFCreateDirRec(GeGetPluginPath() + Filename("tempScenes"));

	if (!SaveDocument(doc, GeGetPluginPath() + Filename("tempScenes/mtstemp.dae"), SAVEDOCUMENTFLAGS_DIALOGSALLOWED |
		SAVEDOCUMENTFLAGS_SAVEAS | SAVEDOCUMENTFLAGS_EXPORTDIALOG, 1022316)){
		MessageDialog("export error");
	}
	else {
		//MessageDialog("export fine");
		//if (!GeExecuteFile(Filename("G:/Program Files/Rockstar Games/Grand Theft Auto V/PlayGTAV.exe"))) MessageDialog("program launch failed");
	//	if (!GeExecuteFile(Filename("C:/Program Files(x86)/MozillaFirefox/firefox.exe"))) MessageDialog("program launch failed");
	//	if (!GeExecuteProgram(Filename("‪C:/Users\marwik15\Desktop\Mitsuba 0.5.0\mtsgui.exe"), Filename("‪C:/Users/marwik15/Desktop/mts stuff/sssdragon/sssdragon.xml"))) MessageDialog("program launch failed");
		//GeExecuteFile("‪C:/Users\marwik15\Desktop\Mitsuba 0.5.0\mtsgui.exe");

		const String argMTS = "-v";

		//if (!GeExecuteProgram("C:/Users/marwik15/Desktop/Mitsuba 0.5.0/mtsimport.exe", "-v X:\HH\Fox_LP.obj" "C:\Users\marwik15\Desktop\mts stuff\room mitsuba test\mts_import_console.xml "))  MessageDialog("program launch failed");
		if (!GeExecuteProgram("C:/Users/marwik15/Desktop/Mitsuba 0.5.0/mitsuba.exe \"C:/Users\marwik15\Desktop\mts stuff\cbox\cbox.xml\"", " \"C:/Users\marwik15\Desktop\mts stuff\cbox\cbox.xml \""))  MessageDialog("program launch failed");
	}
	


	
	//KillDocument(doc);

	//MessageDialog("here still works");
	GePrint("   ");
	GePrint("testowy test testowego pluginu wygląda na zaladowany poprawnie ;DxP" );
	GePrint("   ");


	return true;
}

Bool RegisterMyMts(void)
{
	// be sure to use a unique ID obtained from www.plugincafe.com
	return RegisterCommandPlugin(1039026, GeLoadString(IDS_MYMTS), 0, AutoBitmap("mtsgui.tif"), String("kappa Plugin"), NewObjClear(MyMts));
}

