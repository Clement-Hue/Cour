
public class UnknownVilleException extends Exception {

	private static final String ERROR_MESSAGE = "Ville invalide";
	private static final long serialVersionUID = 1L;
	

	public UnknownVilleException() {
		super(UnknownVilleException.ERROR_MESSAGE);
	}

	public UnknownVilleException(String message, Throwable cause, boolean enableSuppression, boolean writableStackTrace) {
		super(message, cause, enableSuppression, writableStackTrace);
	}

	public UnknownVilleException(String message, Throwable cause) {
		super(message, cause);
	}

	public UnknownVilleException(String message) {
		super(message);
	}

	public UnknownVilleException(Throwable cause) {
		super(UnknownVilleException.ERROR_MESSAGE, cause);
	}

}
