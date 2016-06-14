﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace FMS_adapter
{
    class Program
    {

        //List<FCB> fcbList;

        public static string ToStringProperty(object t)
        {
            string str = "";
            foreach (PropertyInfo item in t.GetType().GetProperties())
                str += "\n" + item.Name + ": " + item.GetValue(t, null);
            return str;
        }

        static void Main(string[] args)
        {

            try
            {
                int structSize = Marshal.SizeOf(typeof(VolumeHeader));
                Console.WriteLine("Marshal.SizeOf(typeof(VolumeHeader) == " + structSize);

                Disk d = new Disk();
                Console.WriteLine("\nMake Disk:");
                //Console.WriteLine(ToStringProperty(d.GetVolumeHeader()));
                
                d.createDisk("disk1", "oshri", "password");
                Console.WriteLine("\nCreate Disk:");
               // Console.WriteLine(ToStringProperty(d.GetVolumeHeader()));

                d.mountDisk("disk1");
                d.format();
                Console.WriteLine("\nFormat Disk:");
                //Console.WriteLine(ToStringProperty(d.GetVolumeHeader()));
            }
            catch (Exception e)
            {
                Console.ForegroundColor = ConsoleColor.Red;
                Console.WriteLine(e.Message);
                Console.ResetColor();
            }
        }

    }
}
