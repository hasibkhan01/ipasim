﻿namespace JJones.IPASimulator.Model.MachO.Commands
{
    public class LoadCommand
    {
        public const uint StructureSize = 8;

        public LoadCommand(LoadCommandType type, uint size)
        {
            Type = type;
            Size = size;
        }

        public LoadCommandType Type { get; }
        public uint Size { get; }
    }
}