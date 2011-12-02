#include "logging_logger.h"

int main(int argc, char *argv[])
{
	g_type_init();

	LoggingLogger *logger = g_object_new(LOGGING_TYPE_LOGGER, NULL);

	logger->name = "chipy";
	logging_logger_log(logger, "ChiPy thanks crowdSPRING for hosting!");
	logging_logger_log(logger, "And can't wait for 'beer time'.");
	logging_logger_log(logger, "The Ruby folk are probably drinking vitamin water right now.");
	logging_logger_increment(logger);
	logging_logger_log(logger, "ChiPy does not have a drinking problem.");
	
	g_object_unref(logger);

	return 0; 
}
