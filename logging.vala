
namespace Logging {
	public class Logger : Object {
		public void log(string msg) {
			stdout.printf("%s %d: %s\n", _name, _count, msg);
			_count++;
		}

		public void increment() {
			_count++;
		}

		public string name {
			get { return _name; }
			set { _name = value; }
		}

		private string _name = "default";

		private int _count = 0;
	}
}
