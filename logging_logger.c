// See: http://arbingersys.blogspot.com/2009/07/missing-gobject-tutorial-sample.html

#include "logging_logger.h"

G_DEFINE_TYPE(LoggingLogger, logging_logger, G_TYPE_OBJECT);

#define LOGGING_LOGGER_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj), LOGGING_TYPE_LOGGER, LoggingLoggerPrivate))

struct _LoggingLoggerPrivate
{
	int count;
};

static void logging_logger_class_init(LoggingLoggerClass *klass)
{
  	g_type_class_add_private(klass, sizeof(LoggingLoggerPrivate));
	klass->log = logging_logger_log_default;
}

static void logging_logger_init(LoggingLogger *self)
{
	self->name = "default";
	self->priv = LOGGING_LOGGER_GET_PRIVATE(self);
	self->priv->count = 0;
}

/**
 * logging_logger_log:
 * @self: the logger
 * @msg: the log message
 * 
 * Sends the log message to the logger.
 */ 
void logging_logger_log(LoggingLogger *self, gchar *msg) {
	g_return_if_fail(LOGGING_IS_LOGGER(self));

	LOGGING_LOGGER_GET_CLASS(self)->log(self, msg);  
}

void logging_logger_log_default(LoggingLogger *self, gchar *msg) {
	g_return_if_fail(LOGGING_IS_LOGGER(self));

	g_print("%s %d: %s\n", self->name, self->priv->count, msg);
	self->priv->count++;
}

void logging_logger_increment(LoggingLogger *self) {
	g_return_if_fail(LOGGING_IS_LOGGER(self));

	self->priv->count++;
}
