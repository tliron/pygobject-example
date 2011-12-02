#include "logging_logger.h"

int main(int argc, char *argv[])
{
	g_type_init();

	LoggingLogger *logger = g_object_new(LOGGING_TYPE_LOGGER, NULL);

	GValue name = G_VALUE_INIT;
	g_value_init(&name, G_TYPE_STRING);
	g_value_set_static_string(&name, "chipy");
	g_object_set_property(G_OBJECT(logger), "name", &name);
	g_value_unset(&name);

	logging_logger_log(logger, "ChiPy thanks crowdSPRING for hosting!");
	logging_logger_log(logger, "And can't wait for 'beer time'.");
	logging_logger_log(logger, "The Ruby folk are probably drinking vitamin water right now.");
	logging_logger_increment(logger);
	logging_logger_log(logger, "ChiPy does not have a drinking problem.");
	
	g_object_unref(logger);

	return 0; 
}
