#include "VHD.h"
#include<string>
/*************************************************
* FUNCTION
*	Ctor for VHD (Volume Header)
* PARAMETERS
*   unsigned int - sector number
*	char[12] - disk name
*	char[12] - disk owner
*	char[10] - production date;
*	unsigned int - amount of clusters on disk;
*	unsigned int - amount of  data clusters on disk;
*	unsigned int - address of sector containing the DAT;
*	unsigned int - address of cluster containing the Root Directory;
*	unsigned int - copy of address of sector containing the DAT;
*	unsigned int - copy of address of cluster containing the Root Directory;
*	unsigned int - address of first Data cluster;
*	char[10] - date of format;
*	bool - is the disk Formated?;
* RETURN VALUE
*	---
* MEANING
*     This function initializes the VHD class
* SEE ALSO
*	---
**************************************************/
VHD::VHD(unsigned int sn,const char dn[12],const char Do[12],const char pd[10], unsigned int cq, unsigned int dcq,
	unsigned int adat, unsigned int ard, unsigned int adc, unsigned int ardc, unsigned int ads,
	const char fd[10], bool is,unsigned int aus)
{
	sectorNr = sn;
	strncpy_s(diskName,12,dn,11);
	strncpy_s(diskOwner,12, Do,11);
	strcpy_s(prodDate, pd);
	ClusQty = cq;
	dataClusQty = dcq;
	addrDAT = adat;
	addrRootDir = ard;
	addrDATcpy = adc;
	addrRootDirCpy = ardc;
	addrDataStart = ads;
	strcpy_s(formatDate, fd);
	isFormatted = is;
	addrUserSec = aus;
}
