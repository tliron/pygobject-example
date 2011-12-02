
namespace Logging {
	public class Logger : Object {
		public void log(string msg) {
			stdout.printf("%s %d: %s\n", name, count, msg);
			count++;
		}

		public void increment() {
			count++;
		}
		
		public string name = "default";

		public int count = 0;
	}
}
