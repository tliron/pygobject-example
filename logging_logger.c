// See: http://arbingersys.blogspot.com/2009/07/missing-gobject-tutorial-sample.html

#include "logging_logger.h"

G_DEFINE_TYPE(LoggingLogger, logging_logger, G_TYPE_OBJECT);

#define LOGGING_LOGGER_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj), LOGGING_TYPE_LOGGER, LoggingLoggerPrivate))

struct _LoggingLoggerPrivate
{
	int count;
};

enum
{
	PROP_0,
	PROP_NAME
};

static void logging_logger_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
	LoggingLogger *self = LOGGING_LOGGER(object);
	switch(property_id)
	{
		case PROP_NAME:
			g_value_set_string(value, self->name);
			break;
	}
}

static void logging_logger_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
	LoggingLogger *self = LOGGING_LOGGER(object);
	switch(property_id)
	{
		case PROP_NAME:
			g_free(self->name);
			self->name = g_value_dup_string(value);
			break;
	}
}

static void logging_logger_class_init(LoggingLoggerClass *klass)
{
  	g_type_class_add_private(klass, sizeof(LoggingLoggerPrivate));
  	
	GObjectClass *gobject_class = G_OBJECT_CLASS(klass);
	gobject_class->get_property = logging_logger_get_property;
	gobject_class->set_property = logging_logger_set_property;
	GParamSpec *pspec;
	pspec = g_param_spec_string("name", "logger name", "The logger's name", "default", G_PARAM_READWRITE);
	g_object_class_install_property(gobject_class, PROP_NAME, pspec);
	
	klass->log = logging_logger_log_default;
}

static void logging_logger_init(LoggingLogger *self)
{
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
