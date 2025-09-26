using System;
using System.Linq;

class Program
{
    static void Main()
    {
        Console.Write("\nEnter the reference string:\n\n>> ");
        string? input = Console.ReadLine();
        if (string.IsNullOrWhiteSpace(input))
        {
            Console.WriteLine("\n\nERROR: Input cannot be empty!\n\n");
            return;
        }

        int[] referenceString = Array.ConvertAll(
            input.Split(' ', StringSplitOptions.RemoveEmptyEntries),
            int.Parse
        );

        Console.Write("\nEnter the number of frames: ");
        input = Console.ReadLine();
        if (string.IsNullOrWhiteSpace(input) ||
            !int.TryParse(input, out int frameCount) ||
            frameCount <= 0)
        {
            Console.WriteLine("\n\nERROR: Invalid number of frames!\n\n");
            return;
        }

        int numberOfPageFaults = 0;
        Queue<int> frames = new(frameCount);

        Console.WriteLine("\n\n--- FIFO Page Replacement Simulation ---\n\n");

        foreach (int page in referenceString)
        {
            Console.Write($"({page})  •  ");
            
            if (frames.Contains(page))
            {
                Console.Write($"{string.Join("\t", frames)}  •  (=)\n");
            }
            else
            {
                numberOfPageFaults++;

                if (frames.Count == frameCount)
                {
                    frames.Dequeue();
                }

                frames.Enqueue(page);
                Console.Write($"{string.Join("\t", frames)}  •  (+)  PF No. {numberOfPageFaults}\n");
            }
        }

        Console.Write($"\n\nTotal Page Faults: {numberOfPageFaults}\n\n");
    }
}
