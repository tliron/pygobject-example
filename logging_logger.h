
#ifndef __LOGGER_H__
#define __LOGGER_H__

#include <glib-object.h>

typedef struct _LoggingLogger			LoggingLogger;
typedef struct _LoggingLoggerClass		LoggingLoggerClass;
typedef struct _LoggingLoggerPrivate	LoggingLoggerPrivate;

/**
 * LoggingLogger:
 * @name: the logger's name
 * 
 * Represents a logger.
 */
struct _LoggingLogger
{
	// This is reserved space for the parent class
	GObject parent_instance;

	/*
	 * logging_logger
	 */
	gchar *name;

	// Private data
	LoggingLoggerPrivate *priv;
};

struct _LoggingLoggerClass
{
	// This is reserved space for the parent class
	GObjectClass parent_class;

	// Virtual methods
	void (*log) (LoggingLogger *self, gchar *msg);
};

void logging_logger_log(LoggingLogger *self, gchar *msg);
void logging_logger_log_default(LoggingLogger *self, gchar *msg);
void logging_logger_increment(LoggingLogger *self);

GType logging_logger_get_type(void);

#define LOGGING_TYPE_LOGGER				(logging_logger_get_type())
#define LOGGING_LOGGER(obj)				(G_TYPE_CHECK_INSTANCE_CAST((obj), LOGGING_TYPE_LOGGER, LoggingLogger))
#define LOGGING_IS_LOGGER(obj)			(G_TYPE_CHECK_INSTANCE_TYPE((obj), LOGGING_TYPE_LOGGER))

#define LOGGING_LOGGER_CLASS(klass)		(G_TYPE_CHECK_CLASS_CAST((klass), LOGGING_TYPE_LOGGER, LoggingLoggerClass))
#define LOGGING_IS_LOGGER_CLASS(klass)	(G_TYPE_CHECK_CLASS_TYPE((klass), LOGGING_TYPE_LOGGER))
#define LOGGING_LOGGER_GET_CLASS(obj)	(G_TYPE_INSTANCE_GET_CLASS((obj), LOGGING_TYPE_LOGGER, LoggingLoggerClass))

#endif
