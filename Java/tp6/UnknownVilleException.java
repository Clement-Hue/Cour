
public class UnknownVilleException extends Exception {

	private static final long serialVersionUID = -5491826477563065568L;
	private static final String ERROR_MESSAGE = "Ville inconnue";

	public UnknownVilleException() {
		super(UnknownVilleException.ERROR_MESSAGE);
	}

	public UnknownVilleException(final String message) {
		super(message);
	}

	public UnknownVilleException(final String message, final Throwable cause) {
		super(message, cause);
	}

	public UnknownVilleException(final String message, final Throwable cause, final boolean enableSuppression,
			final boolean writableStackTrace) {
		super(message, cause, enableSuppression, writableStackTrace);
	}

	public UnknownVilleException(final Throwable cause) {
		super(UnknownVilleException.ERROR_MESSAGE, cause);
	}

}
